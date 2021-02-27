


class ProductOfNumbers {
public:
    ProductOfNumbers() {
        
    }
    
    vector<int> v;
    vector<int> table;
    
    void add(int num) {
        v.push_back(num);
    }
    
    int getProduct(int k) {
        
        int i, product = 1, end;
        end = v.size()-k;
        for(i=v.size()-1;i>=end;i--){
        	product = product * v[i];
        }

        return product;
    }
};
