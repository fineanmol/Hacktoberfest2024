def merge(left_lst, right_lst):
    sorted_list = []
    ll_index = rl_index = 0

    ll_length, rl_length = len(left_lst), len(right_lst)

    for x in range(ll_length+rl_length):
        if ll_index <ll_length and rl_index < rl_length:
            if left_lst[ll_index] <= right_lst[rl_index]:
                sorted_list.append(left_lst[ll_index])
                ll_index += 1
            else:
                sorted_list.append(right_lst[rl_index])
                rl_index += 1
        elif ll_index == ll_length:
            sorted_list.append(right_lst[rl_index])
            rl_index += 1
        elif rl_index == rl_length:
            sorted_list.append(left_lst[ll_index])
            ll_index += 1

    return sorted_list



def merge_sort(nums):
    if len(nums)<=1:
        return nums
    mid = len(nums)//2

    ll = merge_sort(nums[:mid])
    rl = merge_sort(nums[mid:])

    return merge(ll, rl)


rand_list = [9,8,11,5,4,3,2,1,0]
rand_list = merge_sort(rand_list)

print(rand_list)