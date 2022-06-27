#include <mlx.h>

typedef struct s_data {

	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	line_maker(t_data *data, int x_inc, int y_inc, int x_start, int y_start)
{

	int	x;
	int	y;

	x = 0;
	y = 0;
	if (y_inc == 0)	
		while ( x_inc >= x)
			my_mlx_pixel_put(data, x_start + x++, y_start, 0x00FF0000);
	else
		while ( y_inc >= y)
			my_mlx_pixel_put(data, x_start,  y_start + y++, 0x00FF0000);

}

void	squre_maker(t_data *data, int inc, int x, int y)
{

	line_maker(data, inc, 0, x, y);
	line_maker(data, 0, inc, x, y);
	line_maker(data, inc, 0, x, y + inc);
	line_maker(data, 0, inc, x + inc, y);
	return ;
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello World");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	line_maker(&img, 0, 300, 200, 300); // start from ㅂ
	line_maker(&img, 0, 300, 500, 300);
	squre_maker(&img, 300, 200, 600); // end to ㅂ
	
	line_maker(&img, 0, 800, 600, 200); // start from ㅏ 
	line_maker(&img, 300, 0, 600, 600); // end to ㅏ
	
	line_maker(&img, 0, 200, 1120, 100); // start from ㅂ
	line_maker(&img, 0, 200, 1470, 100);
	squre_maker(&img, 350, 1120, 300); // end to ㅂ

	line_maker(&img, 0, 250, 1295, 650);// start from ㅗ
	line_maker(&img, 600, 0, 950, 900);// end to ㅗ
//	my_mlx_pixel_put(&img, 100, 100, 0x00FF0000);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
