fn main() {
    let mut i: i32 = 0;
    while i < 10 {
        if i == 5 {
            i = i + 1;
            continue;
        }
        if i > 7 {
            break;
        }
        i = i + 1;
    }
}