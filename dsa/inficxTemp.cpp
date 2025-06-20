#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<stack>
  
using namespace std ;

int priority( char ch ) {
      if ( ch == '^')
      return 3 ;
      
      else if ( ch =='*' || ch == '/')
      return 2 ; 
      
      else if ( ch == '+'  || ch == '-')
      return 1 ; 
      
      return 0 ; 
  }
    string infixToPostFix(string& s) {
       
       stack < char > st ; 
       string ans = "" ; 
       for ( int i = 0; i < s.size() ; i++) {
           if ( isalnum(s[i])){
               ans = ans + s[i] ; 
           }
           else if ( s[i] == '(')
           st.push(s[i]) ; 
           else if ( s[i] ==')')
           {
               while ( st.top() != '('  && !st.empty()){
               ans = ans + st.top() ; 
               st.pop() ;
               }
            //   remove the (
            st.pop() ; 
           }
           
           else {
           while ( !st.empty() && priority( st.top()) >= priority( s[i]) ) {
           ans = ans + st.top() ; 
           st.pop() ; 
           }
           st.push(s[i]) ; 
               
           }
       }
        while ( !st.empty()) {
             ans = ans + st.top() ;
             st.pop() ; 
        }
        return ans  ;      
        
    }

int main () {

    string str = "a+b*(c^d-e)^(f+g*h)-i" ; 
    string ans = infixToPostFix( str ) ; 
    cout << ans ; 


return 0 ;
}