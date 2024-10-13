public class RevArrayByRecUsingSinleVariable {

public void rev(int [] arr, int i){

int n = arr.length;
if(i >= n/2)
return;

int temp = arr[i];
arr[i] = arr[n-i-1];
arr[n -i-1] = temp;

rev(arr, i + 1);
}

public static void main (String [] args){

int [] arr = {7, 8, 9, 10, 11, 12, 13};

RevArrayByRecUsingSinleVariable rabrusv = new RevArrayByRecUsingSinleVariable();

rabrusv.rev(arr, 0);

 for (int num : arr) {
            System.out.print(num + " ");
        }


}
}
