﻿using Contract;

namespace OneSpaceRule
{
	public class OneSpace : IRule
	{
		public string Name => "OneSpace";

		public List<string> Requirements { get; set; }

		public string Rename(string inp)
		{
			return (string.Join(" ", inp.Split(" ", StringSplitOptions.RemoveEmptyEntries)));
		}
	}
}