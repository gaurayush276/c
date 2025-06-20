#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
#include<map>
#include<stack>
#include<queue>
#include<set>
#include<unordered_set>
#include<unordered_map>
#include<queue>
using namespace std ;
 
    string reverseWords(string s) {
        string ans = "" ; 
        int i = 0 ; 
        int r = 0 ; 
        int l = 0 ;
        reverse(s.begin(),s.end()); 
        string temp = s ; 
        while ( i < s.size()) {
            while ( i < s.size() &&  s[i] != ' ')
            s[r++] = s[i++ ] ;
            if ( l < r )
            {
                reverse(s.begin() + l , s.begin() + r ) ; 
                s[r]= ' ' ;
                r++ ; 
                l = r ;  
            }
            i++ ; 
            cout << temp <<endl ;
            cout << s <<endl  ; 
        }

        cout <<endl ; 
        return s.substr( 0 , r -1 ) ; 

    }
  

int main () {
   string st = "a good  example" ;
   string ans = reverseWords ( st ) ; 
   cout << ans ; 


return 0 ;
}