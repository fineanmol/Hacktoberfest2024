/* Dynamic Programming top-down implementation of Box
 * Stacking problem */
#include <bits/stdc++.h>
using namespace std;
 
/* Representation of a box */
class Box {
public:
    int length;
    int width;
    int height;
};
 
// dp array
int dp[303];
 
/*
    boxes -> vector of Box
    bottom_box_index -> index of the bottom box
    index -> index of current box
*/
/* NOTE: we can use only one variable in place of bottom_box_index and index
     but it has been avoided to make it simple */
int findMaxHeight(vector<Box>& boxes, int bottom_box_index, int index)
{
 
    // base case
    if (index < 0)
        return 0;
 
    if (dp[index] != -1)
        return dp[index];
 
    int maximumHeight = 0;
 
    // recurse
    for (int i = index; i >= 0; i--) {
 
        // if there is no bottom box
        if (bottom_box_index == -1
 
            // or if length & width of new box is < that of
            // bottom box
            || (boxes[i].length
                    < boxes[bottom_box_index].length
                && boxes[i].width
                       < boxes[bottom_box_index].width))
 
            maximumHeight
                = max(maximumHeight,
                      findMaxHeight(boxes, i, i - 1)
                          + boxes[i].height);
    }
 
    return dp[index] = maximumHeight;
}
 
/* wrapper function for recursive calls which
Returns the height of the tallest stack that can be
formed with give type of boxes */
int maxStackHeight(int height[], int width[], int length[],
                   int types)
{
    // creating a vector of type Box class
    vector<Box> boxes;
 
    // Initialize dp array with -1
    memset(dp, -1, sizeof(dp));
 
    Box box;
 
    /* Create an array of all rotations of given boxes
    For example, for a box {1, 2, 3}, we consider three
    instances{{1, 2, 3}, {2, 1, 3}, {3, 1, 2}} */
    for (int i = 0; i < types; i++) {
 
        // copy original box
        box.height = height[i];
        box.length = max(length[i], width[i]);
        box.width = min(length[i], width[i]);
 
        boxes.push_back(box);
 
        // First rotation of box
        box.height = width[i];
        box.length = max(length[i], height[i]);
        box.width = min(length[i], height[i]);
 
        boxes.push_back(box);
 
        // Second rotation of box
        box.height = length[i];
        box.length = max(width[i], height[i]);
        box.width = min(width[i], height[i]);
 
        boxes.push_back(box);
    }
 
    // sort by area in ascending order .. because we will be dealing with this vector in reverse
    sort(boxes.begin(), boxes.end(), [](Box b1, Box b2) {
        // if area of box1 < area of box2
        return (b1.length * b1.width)
               < (b2.length * b2.width);
    });
   
   // Uncomment following two lines to print all rotations
    //for (int i = boxes.size() - 1; i >= 0; i-- )
   //   printf("%d x %d x %d\n", boxes[i].length, boxes[i].width, boxes[i].height);
 
    return findMaxHeight(boxes, -1, boxes.size() - 1);
}
 
int main()
{
 
    // where length, width and height of a particular box
    // are at ith index of the following arrays
    int length[] = { 4, 1, 4, 10 };
    int width[] = { 6, 2, 5, 12 };
    int height[] = { 7, 3, 6, 32 };
 
    int n = sizeof(length) / sizeof(length[0]);
 
    printf("The maximum possible height of stack is %d\n",
           maxStackHeight(height, length, width, n));
 
    return 0;
}
