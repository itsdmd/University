using System;
using System.Drawing;
using System.Text;

// There are three types of graphic objects you need to create in 2D space: 
//	- A line(controlled by two points: start point and end point)
//	- A rectangle(controlled by two points: left top point and right bottom point)
//	- An ellipse(controlled by two points: left top point and right bottom point)

//### Requirements
//Generate randomly 10 objects of three types above. Print out all the generated objects.
//Hint: Override the ToString function

namespace GraphicObjects
{
	class Program
	{
		class Point
		{
			public int X { get; set; }
			public int Y { get; set; }

			public Point()
			{
				Console.WriteLine("Enter X coordinate: ");
				X = int.Parse(Console.ReadLine());

				Console.WriteLine("Enter Y coordinate: ");
				Y = int.Parse(Console.ReadLine());
			}
			
			public Point(int x, int y)
			{
				X = x;
				Y = y;
			}
			
			public override string ToString()
			{
				return ($"({X}, {Y})");
			}
		}

		class GraphicObj
		{
			public string objName { get; set; }
			public List<Point> points { get; set; }
			
			public override string ToString()
			{
				StringBuilder builder = new StringBuilder(objName);
				builder.Append(":");

				foreach (var point in points)
				{
					builder.Append(" ");
					builder.Append(point.ToString());
				}

				return builder.ToString();
			}
		}
		
		class Line : GraphicObj
		{
			public Line()
			{
				objName = "Line";
				
				Point startPnt = new Point();
				Point endPnt = new Point();
				points = new List<Point>() { startPnt, endPnt };
			}

			public Line(Point startPnt, Point endPnt)
			{
				objName = "Line";

				points = new List<Point>() { startPnt, endPnt };
			}
		}

		class Rectangle : GraphicObj
		{
			public Rectangle()
			{
				objName = "Rectangle";

				Point startPnt = new Point();
				Point endPnt = new Point();
				points = new List<Point>() { startPnt, endPnt };
			}

			public Rectangle(Point startPnt, Point endPnt)
			{
				objName = "Rectangle";

				points = new List<Point>() { startPnt, endPnt };
			}
		}

		class Ellipse : GraphicObj
		{
			public Ellipse()
			{
				objName = "Ellipse";

				Point startPnt = new Point();
				Point endPnt = new Point();
				points = new List<Point>() { startPnt, endPnt };
			}

			public Ellipse(Point startPnt, Point endPnt)
			{
				objName = "Ellipse";

				points = new List<Point>() { startPnt, endPnt };
			}
		}

		// TODO: RNG

		static void Main(string[] args)
		{
			
		}
	}
}