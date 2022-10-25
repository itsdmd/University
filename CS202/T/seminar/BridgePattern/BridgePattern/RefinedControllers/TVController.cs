using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BridgePattern
{
	internal class TVController : BaseController
	{
		public TVController(IDevice device) : base(device) { }

		public override void ChannelUp()
		{
			if (_device.IsEnabled() == false)
			{
				_device.Log("Cannot change channel. Device is disabled.");
				return;
			}

			if (_device.GetChannel() == _device.GetLimits()["CHN_MAX"])
			{
				_device.SetChannel(_device.GetLimits()["CHN_MIN"]);
			}
			else
			{
				_device.SetChannel(_device.GetChannel() + 1);
			}
		}

		public override void ChannelDown()
		{
			if (_device.IsEnabled() == false)
			{
				_device.Log("Cannot change channel. Device is disabled.");
				return;
			}

			if (_device.GetChannel() == _device.GetLimits()["CHN_MIN"])
			{
				_device.SetChannel(_device.GetLimits()["CHN_MAX"]);
			}
			else
			{
				_device.SetChannel(_device.GetChannel() - 1);
			}
		}

		// Platform-specic methods
		public void Mute()
		{
			if (_device.IsEnabled() == false)
			{
				_device.Log("Cannot change volume. Device is disabled.");
				return;
			}

			_device.SetVolume(0);
		}
	}
}
