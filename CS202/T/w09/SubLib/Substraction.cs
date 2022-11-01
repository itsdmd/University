using Contract;

namespace SubLib
{
	public class Substraction : IPlugin
	{
		public int Calc(int a, int b)
		{
			return (a - b);
		}
	}
}