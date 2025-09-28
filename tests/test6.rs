fn inc(x: i32) -> i32 { return x + 1; }
fn add(a: i32, b: i32) -> i32 { return a + b; }

fn main() {
    let k = add(inc(1), inc(2));
}
