int reverse(int x){
     int reversez = 0;
        while(x!=0){
            int lastdigit = x%10;
            
            if((reversez > INT_MAX/10) || (reversez < INT_MIN/10)){
                return 0;
            }
            
            reversez = (reversez*10) + lastdigit;
            x = x/10;
        }
        return reversez;
}