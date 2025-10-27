#ifndef DEBUG_H
#define DEBUG_H

#include<bits/stdc++.h>
using namespace std;

void _print(long long t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(long double t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(unsigned long long t) {cerr << t;}

template <class T, class V> void _print(pair<T, V> p);
template <class T> void _print(vector<T> v);
template <class T> void _print(set<T> v);
template <class T> void _print(multiset<T> v);
template <class T> void _print(queue<T> v);
template <class T> void _print(priority_queue<T> v);
template <class T, class V> void _print(map<T, V> v);
template <class T, class V> void _print(pair<T, V> p) {cerr << "{"; _print(p.first); cerr << ","; _print(p.second); cerr << "}";}
template <class T> void _print(vector<T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set<T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(queue<T> v) {cerr << "[ "; while (sz(v)) {_print(v.front()); v.pop(); cerr << " ";} cerr << "]";}
template <class T> void _print(priority_queue<T> v) {cerr << "[ "; while (sz(v)) {_print(v.top()); v.pop(); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset<T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map<T, V> v) {cerr << "[ "; for (auto i : v) {cerr << "{"; _print(i.first); cerr << ","; _print(i.second); cerr << "} ";} cerr << "]";}

#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;

#endif
