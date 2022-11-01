using Contract;

namespace DivLib
{
	public class Division : IPlugin
	{
		public int Calc(int a, int b)
		{
			return (a / b);
		}
	}
}