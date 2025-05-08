/*
static int	get_curr_row(int i, float width)
{
	return ((i - 2) / (int)width);
}

static int	get_curr_col(int i, float width)
{
	return ((i - 2) % (int)width);
}

static int	check_input(float *m_matrix, int row_rm, int col_rm)
{
	if (!m_matrix || row_rm < 0 || col_rm < 0)
		return (0);
	if (row_rm >= m_matrix[0] || col_rm >= m_matrix[1])
		return (0);
	return (1);
}

float	*submatrix(float *m_matrix, int row_rm, int col_rm)
{
	float	*m_sub;
	int		i;
	int		j;
	int		total;

	if (!check_input(m_matrix, row_rm, col_rm))
		return (NULL);
	m_sub = create_matrix(m_matrix[0] - 1, m_matrix[1] - 1);
	if (!m_sub)
		return (NULL);
	i = 2;
	j = 2;
	total = (m_matrix[0] * m_matrix[1]) + 2;
	while (i < total)
	{
		if (get_curr_row(i, m_matrix[1]) != row_rm
			&& get_curr_col(i, m_matrix[1]) != col_rm)
		{
			m_sub[j] = m_matrix[i];
			j++;
		}
		i++;
	}
	return (m_sub);
}*/