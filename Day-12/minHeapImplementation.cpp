class heap{
    vector<int> vec;
    public:
    heap(){ } // just decleared
    
    void insert(int a){
        vec.push_back(a); // we have our newly inserted element at the last index of vec
        // Now we have to place it in correct position [Bottom Up]
        int childIndex=vec.size()-1;
        while(childIndex > 0){
            int parentIndex = (childIndex-1)/2;
            // Min Heap: parent < child. SWAP CONDITION: parent > child
            if(vec[parentIndex] > vec[childIndex]){ // time to swap
                swap(vec[parentIndex], vec[childIndex]);
            }
            else if(vec[parentIndex] <= vec[childIndex]){ return; }
            childIndex=parentIndex;
        }
    }
    bool empty(){
        return (vec.size()==0);
    }
    int top(){
        if(!empty()){
            return vec[0];
        }
        return -1; // heap is empty
    }
    void remove(){
        if(empty()){ return; }// heap is empty
        // I have to remove top i.e vec[0]
        swap(vec[vec.size()-1], vec[0]); vec.pop_back();
        // the ele I want to remove has been removed, but now I have to place vec[0] in its correct pos [Top Down]
        int parentIndex=0;
        while(1){
            int leftChild=(2*parentIndex)+1;
            int rightChild=(2*parentIndex)+2;
            int size=vec.size();
            
            if(leftChild >= size && rightChild >= size){ // none of the child is accesible
                return;
            }
            else if(leftChild >= size && rightChild < size){ // only right is accesible
                if(vec[parentIndex] > vec[rightChild]){
                    swap(vec[parentIndex], vec[rightChild]);
                    parentIndex=rightChild;
                }
                else{ return; }
            }
            else if(leftChild < size && rightChild >= size){ // only left is accesible
                if(vec[parentIndex] > vec[leftChild]){
                    swap(vec[parentIndex], vec[leftChild]);
                    parentIndex=leftChild;
                }
                else{ return; }
            }
            else if(leftChild < size && rightChild < size){ // both child is accesible
                
                if(vec[parentIndex] < vec[leftChild] && vec[parentIndex]< vec[rightChild]){ return; }
                else if(vec[parentIndex] < vec[leftChild] && vec[parentIndex]>= vec[rightChild]){
                    swap(vec[parentIndex], vec[rightChild]);
                    parentIndex=rightChild;
                }
                else if(vec[parentIndex] >= vec[leftChild] && vec[parentIndex] < vec[rightChild]){
                    swap(vec[parentIndex], vec[leftChild]);
                    parentIndex=leftChild;
                }
                else if(vec[parentIndex] >= vec[leftChild] && vec[parentIndex] >= vec[rightChild]){
                    int minIndex=-1;
                    if(vec[leftChild]<vec[rightChild]){ minIndex= leftChild; } else{ minIndex= rightChild; }
                    swap(vec[parentIndex], vec[minIndex]);
                    parentIndex=minIndex;
                }
            }
        }
        return;
    }
};
vector<int> minHeap(int n, vector<vector<int>>& q) {
    heap h; vector<int> ans;
    for(int i=0; i<n; i++){
        if(q[i][0]==0){ // query for insertion
            h.insert(q[i][1]);
        }
        else if(q[i][0]==1){ // query to print min ele & also delete it
            int minEle=h.top();
            ans.push_back(minEle);
            h.remove();
        }
    }
    return ans;
}
