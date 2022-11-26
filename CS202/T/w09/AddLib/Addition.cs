using Contract;

namespace AddLib
{
	public class Addition : IPlugin
	{
		public int Calc(int a, int b)
		{
			return (a + b);
		}
	}
}