using System;
using System.Drawing;
using System.Text;
using System.Xml.Linq;

// There are three types of graphic objects you need to create in 2D space: 
//	- A line(controlled by two points: start point and end point)
//	- A rectangle(controlled by two points: left top point and right bottom point)
//	- An ellipse(controlled by two points: left top point and right bottom point)
//	Generate randomly 10 objects of three types above. Print out all the generated objects.

namespace GraphicObjects
{
	class Program
	{
		class Point
		{
			public int m_x { get; set; }
			public int m_y { get; set; }

			public Point()
			{
				// Generate random value in range [-100; 100] for X and Y
				m_x = new Random().Next(-100, 100);
				m_y = new Random().Next(-100, 100);
			}
			
			public override string ToString()
			{
				return ($"({m_x}, {m_y})");
			}
		}

		public enum ShapeType
		{
			Line,
			Rectangle,
			Ellipse
		}

		class GraphicObj
		{
			public string m_type = "Base";
			public List<Point> m_points = new();
			public List<string> m_pntName = new();

			public override string ToString()
			{
				StringBuilder builder = new StringBuilder();
				builder.Append(m_type).Append(":");

				int index = 0;
				foreach (var point in m_points)
				{
					builder.Append(" [")
						   .Append(m_pntName[index])
						   .Append(": ")
						   .Append(point.ToString())
						   .Append("]");

					index++;
				}

				return builder.ToString();
			}
		}
		
		class Line : GraphicObj
		{
			Point startPnt = new();
			Point endPnt = new();
			
			public Line()
			{
				m_type = "Line";
				m_points.Add(startPnt);
				m_pntName.Add("Start point");
				m_points.Add(endPnt);
				m_pntName.Add("End point");
			}
		}

		class Rectangle : GraphicObj
		{
			Point topLeft = new Point();
			Point botRight = new Point();
			
			public Rectangle()
			{
				m_type = "Rectangle";
				m_points.Add(topLeft);
				m_pntName.Add("Top left");
				m_points.Add(botRight);
				m_pntName.Add("Bottom right");
			}
		}

		class Ellipse : GraphicObj
		{
			Point topLeft = new Point();
			Point botRight = new Point();
			
			public Ellipse()
			{
				m_type = "Ellipse";
				m_points.Add(topLeft);
				m_pntName.Add("Top left");
				m_points.Add(botRight);
				m_pntName.Add("Bottom right");
			}
		}
		static GraphicObj NewObj(ShapeType type)
		{
			switch (type)
			{
				case ShapeType.Line:
					return new Line();

				case ShapeType.Rectangle:
					return new Rectangle();

				case ShapeType.Ellipse:
					return new Ellipse();

				default:
					throw new NotSupportedException();
			}
		}

		static void Main()
		{
			Random rng = new();
			int numOfObj = 10;

			for (int i = 0; i < numOfObj; i++)
			{
				ShapeType type = (ShapeType)rng.Next(0, 3);
				Console.WriteLine(NewObj(type));
			}
		}
	}
}