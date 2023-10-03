fn quick_sort<T: Ord>(mut arr: Vec<T>) -> Vec<T> {
    if arr.len() <= 1 {
        return arr;
    }

    let pivot = arr.remove(0);
    let mut left = vec![];
    let mut right = vec![];

    for item in arr {
        if item <= pivot {
            left.push(item);
        } else {
            right.push(item);
        }
    }

    let mut sorted_left = quick_sort(left);
    let mut sorted_right = quick_sort(right);

    sorted_left.push(pivot);
    sorted_left.append(&mut sorted_right);

    sorted_left
}

fn main() {
    let arr = vec![10, 80, 30, 90, 40, 50, 70];

    println!("{:?}", arr);
    println!("{:?}", quick_sort(arr));
}
