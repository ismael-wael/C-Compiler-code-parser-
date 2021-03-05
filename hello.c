void main ( )
{
	int x = 5 ;
	for ( ; x < 10 ; x ++ )
	{
		switch ( x )
		{
			case 5 :
				x ++ ;
				break ;
			case 6 :
				x = 5 ;
				break ;
			default :
		}
	}
}
void func ( int x , int y )
{
	if ( x > y )
		return x ;
	else
		return y ;
}

				