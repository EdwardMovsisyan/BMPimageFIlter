
void ChangeColor (int Grid_I, int Grid_J,int scale,Matrix& m )
{
    for (int i1 = Grid_I * scale; i1 < (Grid_I + 1) * scale; ++i1 )
    {
	for (int j1 = Grid_J * scale; j1 < (Grid_J+ 1) * scale; ++j1)
	{
	    if (Grid_I % 2 == 0 && Grid_J % 2 == 0)
	    {
		m.Data[i1][j1].R = 140;
		m.Data[i1][j1].G = 0;
		m.Data[i1][j1].B = 0;

	    }

	    if (Grid_I % 2 == 0 && Grid_J % 2 == 1)
	    {
		m.Data[i1][j1].R = 0;
		m.Data[i1][j1].G = 140;
		m.Data[i1][j1].B = 0;
	    }

	    if (Grid_I % 2 == 1 && Grid_J % 2 == 0)
	    {
		m.Data[i1][j1].R = 0;
		m.Data[i1][j1].G = 0;
		m.Data[i1][j1].B = 140;
	    }

	    if (Grid_I % 2 == 1 && Grid_J % 2 == 1)
	    {
		m.Data[i1][j1].R = 50;
		m.Data[i1][j1].G = 30;
		m.Data[i1][j1].B = 70;
	    }

	}

    }
}
