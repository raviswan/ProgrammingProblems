public class RetainBestCache<K, T extends Rankable> {
 
    /* Constructor with a data source (assumed to be slow) and a cache size */
    public RetainBestCache(DataSource<K,T> ds, int entriesToRetain) {
        // Implementation here
        
    }
    
    /*If the key to rank mapping can be many to 1, and keys are meant to be sufficiently randomly distributed,
    can it be assumed that key can be properly hashed to get a rank*/
    
  //  {1-> "abc", 4-> "abd" , 10-> "pqr"}, size =3, key="xyz->100"
 //{"abc"->1, "abd" -> 4, "pqr" ->10}
     hash("abc") = i;
     {{"abc, Value1"}, {"sgh", Value2}, {"ioss", Value3}};
     
    /* Gets some data. If possible, retrieves it from cache to be fast. If the data is not cached,
     * retrieves it from the data source. If the cache is full, attempt to cache the returned data,
     * evicting the T with lowest rank among the ones that it has available
     * If there is a tie, the cache may choose any T with lowest rank to evict.
     */
    public T get(K key) {
        // Implementation here
        map<int, T> mMap;
        int hashVal =  hash(key);
        int hSize = 0;
        if ( hSize < entriesToRetain && mMap[hashVal] == T.empty() ){
            /*fetch the data from DataSource and add to the map*/
        }
        if(mMap[hashVal]){
          if (T.size() == 1){
              return T;
          else{
             /*traverse the list and returnthe value if key foun*/
          }
        }
        
        
        
         
        
    }
}
 
/*
 * For reference, here are the Rankable and DataSource interfaces.
 * You do not need to implement them, and should not make assumptions
 * about their implementations.
 */
 
public interface Rankable {
    /**
     * Returns the Rank of this object, using some algorithm and potentially
     * the internal state of the Rankable.
     */
    long getRank();
}
 
public interface DataSource<K, T extends Rankable> {
    T get (K key);
}