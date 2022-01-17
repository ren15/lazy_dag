use criterion::{black_box, criterion_group, criterion_main, Criterion};
use rand::Rng;

mod math_op;

fn bench_signal_repo_static(c: &mut Criterion) {
    // let test_md = signal::test_util::get_test_static_md();
    let mut rng = rand::thread_rng();

    let p1 = rng.gen();
    let p2 = rng.gen();
    // let p1 = 10.64734634f64;
    // let p2 = 0.126121225f64;

    c.bench_function("empty", |b| {
        b.iter(|| {});
    });

    c.bench_function("add", |b| {
        b.iter(|| {
            black_box(math_op::add(black_box(p1), black_box(p2)));
        })
    });

    // c.bench_function("add_two", |b| {
    //     b.iter(|| {
    //         black_box(math_op::add(black_box(p1), black_box(p2)));
    //         black_box(math_op::add(black_box(p1), black_box(p2)));
    //     })
    // });

    // c.bench_function("add_two_combined", |b| {
    //     b.iter(|| {
    //         black_box(math_op::add_two(black_box([p1, p2]), black_box([p2, p1])));
    //     })
    // });

    c.bench_function("minus", |b| {
        b.iter(|| {
            black_box(math_op::minus(black_box(p1), black_box(p2)));
        })
    });

    c.bench_function("multiply", |b| {
        b.iter(|| {
            black_box(math_op::multiply(black_box(p1), black_box(p2)));
        })
    });

    c.bench_function("divide", |b| {
        b.iter(|| {
            black_box(math_op::divide(black_box(p1), black_box(p2)));
        })
    });

    // c.bench_function("exp", |b| {
    //     b.iter(|| {
    //         black_box(math_op::exp(black_box(p1)));
    //     })
    // });

    c.bench_function("log", |b| {
        b.iter(|| {
            black_box(math_op::log(black_box(p1)));
        })
    });

    // c.bench_function("power", |b| {
    //     b.iter(|| {
    //         black_box(math_op::power(black_box(p1), black_box(p2)));
    //     })
    // });

    let mut x: [f64; 5] = [0.0; 5];
    for i in x.iter_mut() {
        *i = rng.gen();
    }
    c.bench_function("f_dag", |b| {
        b.iter(|| {
            black_box(math_op::f_dag(black_box(x)));
        })
    });

    let x = [1.0, 2.0, 3.0, 4.0, 5.0];
    c.bench_function("f_dag_compile", |b| {
        b.iter(|| {
            black_box(math_op::f_dag(x));
        })
    });
}

criterion_group!(benches, bench_signal_repo_static,);
criterion_main!(benches);
