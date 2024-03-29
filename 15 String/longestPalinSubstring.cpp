string longestPalindrome(string s) {
        
        if(s.size() <= 1) return s;
        
        int max_len = 0, start_idx = 0;
        int i = 0;
        
        while(i < s.size()){
            int r_ptr = i, l_ptr = i;
            
            while(r_ptr < s.size() - 1 && s[r_ptr] == s[r_ptr + 1]) r_ptr++;
            
            i = r_ptr+1;
            while(r_ptr < s.size() - 1 && l_ptr > 0 && s[r_ptr+1] == s[l_ptr - 1]){
                r_ptr++;
                l_ptr--;
            }
            
            int new_len = r_ptr - l_ptr + 1;
            
            if(new_len > max_len){
                start_idx = l_ptr;
                max_len = new_len;
            }
        }
        
        return s.substr(start_idx, max_len);
    }
