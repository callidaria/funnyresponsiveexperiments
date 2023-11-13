/**
 *	class with simple adaptive implementation in java
 *	DrawFunctions provides class with drawSidebarFinal(width) function
*/
class AdaptiveClass extends DrawFunctions
{
	private float maximumSidebarWidth;

	AdaptiveClass(float maximumSidebarWidth) {

		super();
		this.maximumSidebarWidth = maximumSidebarWidth;

	}

	public drawSidebarAdaptive(int screen_width) {

		if (screenwidth>800)
			super.drawSidebarFinal(maximumSidebarWidth);

	}

}


/**
 *	class with simple responsive implementation in java
 *	DrawFunctions provides class with uploadElementSize(element,x,y,width,height)
*/
class ResponsiveClass extends DrawFunctions
{
	private int maximumColumns;
	private int rasterJump;

	ResponsiveClass(int maximumColumns,int rasterJump) {

		super();
		this.maximumColumns = maximumColumns;
		this.rasterJump = rasterJump;

	}

	public calculateElementGrid(ArrayList<Element> e,int screenWidth) {

		// calculate row range
		int shifter = screenWidth/rasterJump;
		int rowRange = rasterJump>>shifter;

		// calculate element dimensions
		float squareCrop = ((float)screenWidth)/((float)rowRange);

		// upload dimensions ot element draw
		for (Element x : e)
			super.uploadElementSize(x,
					(i%rowRange)*squareCrop,(i/rowRange)*squareCrop,
					squareCrop,squareCrop);

	}
}

