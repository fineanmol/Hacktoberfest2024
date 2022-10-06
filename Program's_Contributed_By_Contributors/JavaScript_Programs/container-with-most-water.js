var maxArea = function(height) {
    let left = 0;
    let right = height.length - 1;
    let maxArea = 0;
    while(left < right )
    {
        let area = Math.min(height[left],height[right]) * (right - left);
        if(area > maxArea) maxArea = area;
        if(height[left] > height[right])
        {
            right--;
        }else{
            left++;

        }
    }
    return maxArea;
};
let a = [1,8,6,2,5,4,8,3,7];
console.log(maxArea(a));