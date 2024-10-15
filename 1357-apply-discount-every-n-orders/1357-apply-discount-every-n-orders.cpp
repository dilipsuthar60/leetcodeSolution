class Cashier {
public:
    unordered_map<int,int>mp;
    int mod;
    double dis;
    int count=0;
    Cashier(int n, int discount, vector<int>& products, vector<int>& prices) {
        for(int i=0;i<products.size();i++){
            mp[products[i]]=prices[i];
        }
        dis=(100.0-discount)/100.0;
        mod=n;
    }
    
    double getBill(vector<int> product, vector<int> amount) {
        double bill=0.0;
        count++;
        for(int i=0;i<product.size();i++){
            bill+=mp[product[i]]*amount[i];
        }
        return count%mod?bill:bill*dis;
    }
};

/**
 * Your Cashier object will be instantiated and called as such:
 * Cashier* obj = new Cashier(n, discount, products, prices);
 * double param_1 = obj->getBill(product,amount);
 */