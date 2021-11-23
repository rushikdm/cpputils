class range
{
	int start, stop, step;
  
public:
	range(const int iStop): range(0, iStop) { }
	range(const int iStart, const int iStop): range(iStart, iStop, (iStop >= iStart ? 1 : -1)) { }
	range(const int iStart, const int iStop, const int iStep): start(iStart), stop(iStop), step(iStep) { }
	
	class iterator
	{
		int index;
		int step;
	public:
		iterator(const int Index, const int iStep): index(Index), step(iStep) { }
		const int operator * () { return index; }
		iterator& operator++() { index+= step; return *this;}
		bool operator != (const iterator& itr) const {return index != itr.index; }
	};
	
	iterator begin() { return iterator(start, step); }
	iterator end() { return iterator(stop, step	); }
};
