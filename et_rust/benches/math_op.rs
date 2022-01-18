#[inline]
pub fn add(a: f64, b: f64) -> f64 {
    a + b
}

#[inline]
pub fn add_two(a: [f64; 2], b: [f64; 2]) -> [f64; 2] {
    [a[0] + b[0], a[1] + b[1]]
}

#[inline]
pub fn minus(a: f64, b: f64) -> f64 {
    a - b
}

#[inline]
pub fn multiply(a: f64, b: f64) -> f64 {
    a * b
}

#[inline]
pub fn divide(a: f64, b: f64) -> f64 {
    a / b
}

#[inline]
pub fn power(a: f64, b: f64) -> f64 {
    a.powf(b)
}

#[inline]
pub fn exp(a: f64) -> f64 {
    a.exp()
}

#[inline]
pub fn log(a: f64) -> f64 {
    a.ln()
}

#[inline]
pub fn f_dag_full(x: [f64; 5]) -> f64 {
    let y1 = x[2] * (5.0 * x[0] + x[1]);
    let y2 = log(y1);
    let y = (y1 + x[3] * y2) * (y1 + y2);
    y
}

#[inline]
pub fn f_dag(x: [f64; 5]) -> f64 {
    let y1 = get_y1(x);
    let y2 = get_y2(y1);
    let y = get_y(y1, y2, x[3]);
    y
}

#[inline]
fn get_y(y1: f64, y2: f64, x3: f64) -> f64 {
    (y1 + x3 * y2) * (y1 + y2)
}

#[inline]
fn get_y2(y1: f64) -> f64 {
    let y2 = log(y1);
    y2
}

#[inline]
fn get_y1(x: [f64; 5]) -> f64 {
    let y1 = x[2] * (5.0 * x[0] + x[1]);
    y1
}
