using Contract;

namespace PowLib
{
	public class Power : IPlugin
	{
		public int Calc(int a, int b)
		{
			return (int)Math.Pow(a, b);
		}
	}
}