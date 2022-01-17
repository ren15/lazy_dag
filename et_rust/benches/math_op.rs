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
