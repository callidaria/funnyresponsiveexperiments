/**
 *	adaptive testing pseudoimplementation in c-style language
*/


#define DRAW_SIDEBAR_EXCLUSION 0

constexpr float MAXIMUM_SIDEBAR_WIDTH = 250.f;


/*
	draw_sidebar_final(float) -> void !O(1)
	\param sidebar_width: width of the sidebar to draw
	purpose: draw sidebar
*/
void draw_sidebar_final(float sidebar_width);
// implementation happens somewhere else


/*
	draw_sidebar_adaptive(uint16_t screen_width) -> void !O(1)
	\param screensize: always changing screenwidth
	purpose: pseudoimplementation of adaptive sidebar removal
*/
void draw_sidebar_adaptive(uint16_t screen_width)
{

#if DRAW_SIDEBAR_EXCLUSION

	if (screenwidth>800) draw_sidebar_final(MAXIMUM_SIDEBAR_WIDTH);

#else

	float sidebar_width = MAXIMUM_SIDEBAR_WIDTH*(screenwidth>800);
	draw_sidebar_final(sidebar_width);

#endif

}




/**
 *	responsive testing pseudoimplementation in c-style language
*/


constexpr uint8_t MAXIMUM_COLUMNS = 8;
constexpr uint16_t RASTER_JUMP = 450;


/*
	upload_element_size(Element*,float,float) -> void !O(n)
	purpose: define element dimensions for draw unit
	\param e: drawable element
	\param x: position on x-axis
	\param y: position on y-axis
	\param width: width of element
	\param height: height of element
*/
void upload_element_size(Element* e,float x,float y,float width,float height);
// implementation happens somewhere else


/*
	calculate_element_grid(Element*,size_t esize,uint16_t) -> void !O(n)
	purpose: calculate element dimensions
*/
void calculate_element_grid(Element* le,size_t esize,uint16_t screen_width)
{
	// calculate row range
	uint8_t shifter = screen_width/RASTER_JUMP;
	uint8_t row_range = RASTER_JUMP>>shifter;

	// calculate element dimensions
	float square_crop = (float)screen_width/row_range;

	// upload dimensions to element draw
	for (size_t i=0;i<esize;i++)
		upload_element_size(&le[i],
				(i%row_range)*square_crop,(i/row_range)*square_crop,
				square_crop,square_crop);
}

