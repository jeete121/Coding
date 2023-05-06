#include <bits/stdc++.h>
using namespace std;

class MyMap
{
  map<int,int >  timedMap;


MyMap()
{
timedMap.clear();
}


void putValueInMap(string key, string value, int time)
{
timedMap.computeIfPresent(key, (k, v) -> {
v.put(time, value);
return v;
});
map<int,int> valueMap;// = new HashMap();
valueMap.put(time, value);
timedMap.putIfAbsent(key, valueMap);

}


public String getValueAtTime(String key, int time)
{
Map map = this.timedMap.get(key);
int index = 0;
final List collected = map.keySet().stream().sorted().collect(Collectors.toList());
for (int num : collected)
{
if (num <= time)
{
index = num;
}
}
return map.get(index);
}
};