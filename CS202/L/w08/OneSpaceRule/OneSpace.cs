﻿using Contract;

namespace OneSpaceRule
{
	public class OneSpace : IRule
	{
		public string Name => "OneSpace";

		public List<string> Parse { get; set; }

		public string Rename(string inp)
		{
			return (string.Join(" ", inp.Split(" ", StringSplitOptions.RemoveEmptyEntries)));
		}
	}
}