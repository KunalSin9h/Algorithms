use std::io::stdin;

fn main() {
    let mut array: Vec<i32>;
    let mut input = String::new();
    stdin()
        .read_line(&mut input)
        .expect("Failed to read array from input");

    array = input
        .trim()
        .split(' ')
        .collect::<Vec<_>>()
        .iter()
        .map(|token| token.parse::<i32>().unwrap())
        .collect();

    let array_length = array.len();
    merge_sort(&mut array, &0, &(array_length - 1));
    println!("{:?}", array);
}

fn merge_sort(array: &mut Vec<i32>, l: &usize, r: &usize) {
    if l < r {
        let m = (l + r) / 2;
        merge_sort(array, l, &m);
        merge_sort(array, &(m + 1), r);
        merge(array, l, &m, r);
    }
}

fn merge(array: &mut Vec<i32>, l: &usize, m: &usize, r: &usize) {
    let left_cnt = m - l + 1;
    let right_cnt = r - m;

    let mut left: Vec<i32> = vec![];
    let mut right: Vec<i32> = vec![];

    for i in *l..(m + 1) {
        left.push(array[i])
    }

    for i in (m + 1)..(r + 1) {
        right.push(array[i])
    }

    let mut i = *l; // the first index of the merging area
    let mut j = 0; // the first index of the left array
    let mut k = 0; // the first index of the right array

    while j < left_cnt && k < right_cnt {
        if left[j] <= right[k] {
            array[i] = left[j];
            j += 1;
        } else {
            array[i] = right[k];
            k += 1;
        }
        i += 1;
    }

    while j < left_cnt {
        array[i] = left[j];
        i += 1;
        j += 1;
    }

    while k < right_cnt {
        array[i] = right[k];
        i += 1;
        k += 1;
    }
}
