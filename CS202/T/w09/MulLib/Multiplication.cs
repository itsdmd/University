using Contract;

namespace MulLib
{
	public class Multiplication : IPlugin
	{
		public int Calc(int a, int b)
		{
			return (a * b);
		}
	}
}