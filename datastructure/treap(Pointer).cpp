struct treap {
	struct Treap{
		int fix, key, size;
		Treap *left, *right;
		Treap() { fix = key = size = left = right = 0; }
	}*root, *null;

	void init()
	{
		null = new Treap;
		root = null;
	}
	void rotate_left(Treap *&p)
	{
		Treap *tmp = p -> right;
		p -> right = tmp -> left;
		int zsize = tmp -> left -> size;
		p -> size = p -> size - tmp -> size + zsize;
		tmp -> left = p;
		tmp -> size = tmp -> size - zsize + p -> size;
		p = tmp;
	}
	void rotate_right(Treap *&p)
	{
		Treap *tmp = p -> left;
		p -> left = tmp -> right;
		int zsize = tmp -> right -> size;
		p -> size = p -> size - tmp -> size + zsize;
		tmp -> right = p;
		tmp -> size = tmp -> size - zsize + p -> size;
		p = tmp;
	}

	void Insert(Treap *&p, int x)
	{
		if(p == null)
		{
			p = new Treap;
			p -> fix = rand();
			p -> key = x;
			p -> size = 1;
			p -> left = null;
			p -> right = null;
			return;
		}
		if(x < p -> key)
		{
			Insert(p -> left, x);
			p -> size++;
			if(p -> left -> fix > p -> fix) rotate_right(p);
		}
		else {
			Insert(p -> right, x);
			p -> size++;
			if(p -> right -> fix > p -> fix) rotate_left(p);
		}
	}
	int Delete_min(Treap *&p)
	{
		p -> size--;
		if(p -> left == null)
		{
			int value = p -> key;
			p = p -> right;
			return value;
		}
		else return Delete_min(p -> left);
	}
	void Delete(Treap *&p, int x) // Make sure that `x` is existed
	{
		if(p == null) return;
		p -> size--;
		if(x < p -> key) Delete(p -> left, x);
		else if(x > p -> key) Delete(p -> right, x);
		else { // delete *p
			if(p -> left == null && p -> right == null)
			{
				p = null;
			}
			else if(p -> left == null || p -> right == null)
			{
				if(p -> left == null)
				{
					p = p -> right;
				}
				else { // p -> right == null
					p = p -> left;
				}
			}
			else { // p -> left != null && p -> right != null
				p -> key = Delete_min(p -> right);
			}
		}
	}
	int Count_leq(Treap *&p, int x)
	{
		if(p == null) return 0;
		if(p -> key <= x) return p -> left -> size + 1 + Count_leq(p -> right, x);
		else return Count_leq(p -> left, x);
	}
	int Count_geq(Treap *&p, int x)
	{
		if(p == null) return 0;
		if(p -> key >= x) return p -> right -> size + 1 + Count_geq(p -> left, x);
		else return Count_geq(p -> right, x);
	}
	int Find_kth(Treap *&p, int x)
	{
		if(k == p -> left -> size + 1) return p -> key;
		if(k <= p -> left -> size) return Find_kth(p -> left, k);
		else return Find_kth(p -> right, k - p -> left -> size - 1);
	}
};
