class DisjointSets{
private:
    vll parent, sizes;
public:
    DisjointSets(ll n){
        parent.resize(n);
        sizes.assign(n, 1);
        for(ll i = 0; i < n; i++) parent[i] = i;
    }
    ll find_set(ll v){
        if(v == parent[v]) return v;
        return parent[v] = find_set(parent[v]);
    }
    void union_sets(ll a, ll b) {
        a = find_set(a);
        b = find_set(b);
        if (a != b){
            if(sizes[a] < sizes[b]) swap(a, b);
            parent[b] = a;
            sizes[a] += sizes[b];
        }
    }
    ll set_size(ll v){
        return sizes[find_set(v)];
    }
    bool same_set(ll a, ll b){
        return find_set(a) == find_set(b);
    }

};
