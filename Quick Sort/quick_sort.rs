use std::io::stdin;

fn main() {
    let mut input = String::new();

    stdin().read_line(&mut input).expect("Failed to read line");

    let mut array: Vec<i32> = input
        .trim()
        .split(' ')
        .collect::<Vec<_>>()
        .iter()
        .map(|token| token.parse::<i32>().unwrap())
        .collect();

    let array_len = array.len() as i32;
    quick_sort(&mut array, &0, &(array_len - 1));
    println!("{:?}", array);
}

fn quick_sort(array: &mut Vec<i32>, l: &i32, r: &i32) {
    if l < r {
        let p = partition(array, l, r);
        quick_sort(array, l, &(p - 1));
        quick_sort(array, &(p + 1), r);
    }
}

fn partition(array: &mut Vec<i32>, l: &i32, r: &i32) -> i32 {
    let pivot = array[*r as usize];
    let mut i = (*l as i32) - 1; // lower bound

    for j in *l..*r {
        if array[j as usize] < pivot {
            i += 1;

            // swap
            array.swap(i as usize, j as usize);
        }
    }

    // swap last element
    array.swap((i + 1) as usize, *r as usize);

    return i + 1;
}
