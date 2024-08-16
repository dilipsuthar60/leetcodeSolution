class Solution {
public:
    const string validIPv6Chars = "0123456789abcdefABCDEF";
    const string validIPv4Chars = "0123456789";
    vector<string>split(string&query,char ch){
        vector<string>parts;
        istringstream ss(query);
        string curr="";
        while(getline(ss,curr,ch)){
            parts.push_back(curr);
        }
        return parts;
    }
    bool isIpv4(string &query){
        if(count(query.begin(),query.end(),'.')!=3) return false;
        vector<string>parts=split(query,'.');
        if(parts.size()!=4) return false;
        for(auto &part:parts){
            if(part.empty()||part.size()>=4) return false;
            if(part[0]=='0'&&part.size()==1) {
                continue;
            }
            if(part[0]=='0') return false;
            for(auto &ch:part){
                if(validIPv4Chars.find(ch)==string::npos){
                    return false;
                }
            }
            int number=stoi(part);
            if(number<1||number>255) return false;
        }
        return true;
    }
    bool isIpv6(string &query){
        if(count(query.begin(),query.end(),':')!=7) return false;
        vector<string>parts=split(query,':');
        if(parts.size()!=8) return false;
        for(auto &part:parts){
            if(part.empty()||part.size()>=5) return false;
            for(auto &ch:part){
                if(validIPv6Chars.find(ch)==string::npos){
                    return false;
                }
            }
        }
        return true;
    }
    string validIPAddress(string query) {
        return isIpv4(query)?"IPv4":(isIpv6(query)?"IPv6":"Neither");
    }
};