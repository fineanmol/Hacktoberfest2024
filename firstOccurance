// Left to right

// TC -> O(N) SC 0(N)

void solve(int input[], int i, int size, int x, int &ans){
  if(i == size){
    return;
  }

  if(input[i] == x){
    ans = i;
    return ;
  }

  solve(input, i + 1, size, x, ans);
}

int firstIndex(int input[], int size, int x) {  
  int ans = -1;
  solve(input,0, size, x, ans);
  return ans;
}


// Right to Left

void solve(int input[], int i, int size, int x, int &ans){
  if(i < 0){
    return;
  }

  if(input[i] == x){
    ans = i;
  }

  solve(input, i - 1, size, x, ans);
}

int firstIndex(int input[], int size, int x) {  
  int ans = -1;
  solve(input,size - 1, size, x, ans);
  return ans;
}


