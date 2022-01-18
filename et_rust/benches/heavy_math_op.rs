use std::{thread, time};

#[derive(Clone, Copy)]
struct HeavyNumber {
    value: f64,
}
impl HeavyNumber {
    fn new(value: f64) -> HeavyNumber {
        HeavyNumber { value }
    }
    fn get_value(&self) -> f64 {
        thread::sleep(time::Duration::from_millis(1));
        self.value
    }
}

#[inline]
pub fn log(a: f64) -> f64 {
    a.ln()
}

// #[inline]
// pub fn f_dag_full(x: [f64; 5]) -> f64 {
//     let y1 = x[2] * (5.0 * x[0] + x[1]);
//     let y2 = log(y1);
//     let y = (y1 + x[3] * y2) * (y1 + y2);
//     y
// }

#[inline]
pub fn f_dag(x: [f64; 5]) -> f64 {
    let x_heavy = {
        let mut x_heavy = [HeavyNumber::new(0f64); 5];
        for (i, v) in x.iter().enumerate() {
            x_heavy[i] = HeavyNumber::new(v.clone());
        }
        x_heavy
    };

    let a = x_heavy[0];
    let b = x_heavy[1];
    let c = x_heavy[2];
    let d = x_heavy[3];
    let e = x_heavy[4];

    let y = a.get_value() * b.get_value()
        + a.get_value() * c.get_value()
        + a.get_value() * d.get_value()
        + a.get_value() * e.get_value();
    y
}

#[inline]
pub fn f_dag_long(x: [f64; 5]) -> f64 {
    let x_heavy = {
        let mut x_heavy = [HeavyNumber::new(0f64); 5];
        for (i, v) in x.iter().enumerate() {
            x_heavy[i] = HeavyNumber::new(v.clone());
        }
        x_heavy
    };
    let a = x_heavy[0];
    let b = x_heavy[1];
    let c = x_heavy[2];
    let d = x_heavy[3];
    let e = x_heavy[4];

    let y = a.get_value() * (b.get_value() + c.get_value() + d.get_value() + e.get_value());
    y
}
