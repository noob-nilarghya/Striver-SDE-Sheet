
// The main point is, we need to find largest possible prefix that is palindrome
int minCharsforPalindrome(string str) {
	int n=str.size();        
	int start=0; int end=n-1;        
	int prevEnd=end; int count=0; 
           
	while(start<end){            
		if(str[start] == str[end]){                
			start++; end--;            
		}            
		else{ 
			count++; 
			start=0; prevEnd--; end=prevEnd;           
		}       
	}       
	return count;	
}

