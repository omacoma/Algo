void dfs(int v){
    used[v] = true;
    for(auto to : g[v])
        if(!used[to])
            dfs(to);
}
