
// MOST TOUGHEST PROBLEM IN WHOLE SDE SHEET [ VERY VERY IMPORTANT ]


    vector<int> nsl(int a[], int n, int dummyLeft){
        vector<int> ans; stack<int> s;
        for(int i=0; i<n; i++){
            if(s.empty()==true){
                ans.push_back(dummyLeft);
            }
            else if(a[s.top()] < a[i]){
                ans.push_back(s.top());
            }
            else if(a[s.top()] >= a[i]){
                while(!s.empty() && a[s.top()]>=a[i]){
                    s.pop();
                }
                if(s.empty()==true){
                    ans.push_back(dummyLeft);
                }
                else if(a[s.top()] < a[i]){
                    ans.push_back(s.top());
                }
            }
            s.push(i);
        }
        return ans;
    }
    
    vector<int> nsr(int a[], int n, int dummyRight){
        vector<int> ans; stack<int> s;
        for(int i=n-1; i>=0; i--){
            if(s.empty()==true){
                ans.push_back(dummyRight);
            }
            else if(a[s.top()] < a[i]){
                ans.push_back(s.top());
            }
            else if(a[s.top()] >= a[i]){
                while(!s.empty() && a[s.top()] >= a[i]){
                    s.pop();
                }
                if(s.empty()==true){
                    ans.push_back(dummyRight);
                }
                else if(a[s.top()] < a[i]){
                    ans.push_back(s.top());
                }
            }
            s.push(i);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }

    vector <int> maxOfMin(int a[], int n){
        vector<int> ans(n, INT_MIN);
        vector<int> NSL= nsl(a, n, -1);
        vector<int> NSR= nsr(a, n, n);
        
        for(int i=0; i<n; i++){
            int leftIdx= NSL[i];
            int rightIdx= NSR[i];
            int diff=rightIdx-leftIdx-2;
            ans[diff]=max(ans[diff],a[i]);
        }
        
        for(int i=n-2; i>=0; i--){
            if(ans[i]<ans[i+1]){
                ans[i]=ans[i+1];
            }
        }
        return ans;
    }
    
