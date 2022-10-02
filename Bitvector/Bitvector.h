class Bitvector
{
    public:
        Bitvector ();
        Bitvector (const Bitvector&) = delete;
        Bitvector (Bitvector&&) = delete;
        Bitvector& operator = (const Bitvector&) = delete;
        Bitvector& operator = (Bitvector&&) = delete;
        void set (const int, const bool);
        bool get (const int);
    private:
        std::vector<int> bit_set;
};

Bitvector::Bitvector () {}

void Bitvector::set (const int pos, const bool bit1)
{
    int table = 0;
    int v_index = pos / 32;
    int b_index = pos % 32;

    for (int i = bit_set.size(); i <= v_index; ++i)
    {
        bit_set.push_back(table);
    }

    if (bit1)
        {
            bit_set[v_index] |= (1 << b_index);
            return;
        }

    int m = (1 << b_index);
    m = ~m;
    bit_set[v_index] &= m;
}

bool Bitvector::get (int pos)
{
    int v_index = pos / 32;
    int b_index = pos % 32;

    return bit_set[v_index] & (1 << b_index);
}