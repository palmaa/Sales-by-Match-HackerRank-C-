int sockMerchant(int n, vector<int> ar) {
    
    
    //Want to know the diferent types of socks we have
    vector<int> items = ar;
    std::sort( items.begin(), items.end() );
    items.erase( unique(items.begin(), items.end()), items.end());
    
    // we use it to iterate in the vector
    std::vector<int>::iterator it = ar.begin();
    
    // our variables
    int coincidences = 0;
    int number_pairs = 0;
    
    
    // we go over our items array to find coincidences for all socks types
    for(int i; i<items.size(); i++){
        
        // while we find coincidences...
        while(it != ar.end()){
            
            // we search for the next coindicence
            it = std::find(it, ar.end(), items[i]);
            
            // if we find another coincidence...
            if(it != ar.end()){
                advance(it, 1);
                coincidences++;
            } 
        }
        
        // when we don't find coincidences, we iterate the array again
        it = ar.begin();
        
        // and we store the number of pairs
        number_pairs += (coincidences/2);
        coincidences = 0;
    }
    
    // we return the result
    return number_pairs;

}
