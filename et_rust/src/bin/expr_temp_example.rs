use std::ops::Neg;

/// This enum represents all supported operations. Only one unary operation
/// supported for now, Neg.
enum Expr<U> {
    Terminal(U),
    Neg(Box<Expr<U>>),
}

// Implement std::ops::Neg for E<U>
impl<U> Neg for Expr<U> {
    type Output = Expr<U>;
    fn neg(self) -> Self::Output {
        Expr::Neg(Box::new(self))
    }
}

trait Transform<U = Self> {
    fn transform<R, F>(&self, _f: F) -> Option<R>
    where
        F: FnMut(&Expr<U>) -> Option<R>,
        R: Neg<Output = R>,
    {
        None
    }
}

impl<U> Transform<U> for Expr<U> {
    fn transform<R, F>(&self, mut f: F) -> Option<R>
    where
        F: FnMut(&Expr<U>) -> Option<R>,
        R: Neg<Output = R>,
    {
        // CASE 1/3: Match! return f(self)
        if let Some(v) = f(self) {
            return Some(v);
        };

        match self {
            Expr::Terminal(_) => None, // CASE 2/3: We have reached a leaf-expression, no match!
            Expr::Neg(x) => {
                // CASE 3/3: Recurse and apply operation to result
                x.transform(f).map(|y| -y)
            }
        }
    }
}

fn main() {
    // An expression template
    let y = ----Expr::Terminal(42);

    // A transform that counts the number of nestings
    // To Do: Not sure if this works with Fn or if I need FnMut, check later
    let mut count = 0;
    y.transform(|x| {
        match x {
            Expr::Neg(_) => {
                count += 1;
                None
            }
            _ => Some(0), // must return something. It doesn't matter what here.
        }
    });
    assert_eq!(count, 4);

    // a transform that replaces the terminal in y with E::Terminal(5)
    let expr = y
        .transform(|x| match *x {
            Expr::Terminal(_) => Some(Expr::Terminal(5)),
            _ => None,
        })
        .unwrap();

    // a transform that evaluates the expression
    // (note: should be provided as method for E<U>)
    let result = expr
        .transform(|x| match *x {
            Expr::Terminal(v) => Some(v),
            _ => None,
        })
        .unwrap();
    assert_eq!(result, 5);
    println!("{}", result);
}
