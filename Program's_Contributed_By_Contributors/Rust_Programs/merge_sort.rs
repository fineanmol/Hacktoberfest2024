fn merge_sort<T: PartialOrd>(v: &mut Vec<T>) -> Vec<T> {
    if v.len() == 1 {
        return vec![v.pop().unwrap()];
    }

    let n = f64::ceil(v.len() as f64 / 2.0) as usize;
    let mut left = merge_sort(&mut v.drain(0..n).collect::<Vec<T>>());
    let mut right = merge_sort(&mut v.drain(..).collect::<Vec<T>>());
    let mut merged = vec![];

    while left.len() > 0 && right.len() > 0 {
        if left[0] <= right[0] {
            merged.push(left.remove(0));
        } else {
            merged.push(right.remove(0));
        }
    }

    merged.append(if left.len() > 0 {
        &mut left
    } else {
        &mut right
    });

    return merged;
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_merge_sort_1() {
        let mut v = vec![3, 1, 5, 6, 2];
        v = merge_sort(&mut v);
        assert_eq!(v, vec![1, 2, 3, 5, 6]);
    }

    #[test]
    fn test_merge_sort_2() {
        let mut v = vec![3.0, 1.0, 5.0, 6.0, 2.0];
        v = merge_sort(&mut v);
        assert_eq!(v, vec![1.0, 2.0, 3.0, 5.0, 6.0]);
    }
}
