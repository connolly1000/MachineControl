/*++

Copyright (C) 2020 Autodesk Inc.

All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:
	* Redistributions of source code must retain the above copyright
	  notice, this list of conditions and the following disclaimer.
	* Redistributions in binary form must reproduce the above copyright
	  notice, this list of conditions and the following disclaimer in the
	  documentation and/or other materials provided with the distribution.
	* Neither the name of the Autodesk Inc. nor the
	  names of its contributors may be used to endorse or promote products
	  derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL AUTODESK INC. BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

*/

#define __AMCIMPL_UI_MODULE
#define __AMCIMPL_API_CONSTANTS

#include "amc_ui_module_contentitem_buttongroup.hpp"
#include "libmc_interfaceexception.hpp"

#include "amc_api_constants.hpp"
#include "Common/common_utils.hpp"

using namespace AMC;

CUIModule_ContentButton::CUIModule_ContentButton(const std::string& sCaption, const std::string& sTargetPage, const std::string& sEvent)
	: m_sUUID (AMCCommon::CUtils::createUUID ()), m_sCaption (sCaption), m_sTargetPage (sTargetPage), m_sEvent (sEvent)
{

}

CUIModule_ContentButton::~CUIModule_ContentButton()
{

}

std::string CUIModule_ContentButton::getUUID()
{
	return m_sUUID;
}

std::string CUIModule_ContentButton::getCaption()
{
	return m_sCaption;
}

std::string CUIModule_ContentButton::getTargetPage()
{
	return m_sTargetPage;
}

std::string CUIModule_ContentButton::getEvent()
{
	return m_sEvent;
}

CUIModule_ContentButtonGroup::CUIModule_ContentButtonGroup()
	: CUIModule_ContentItem(AMCCommon::CUtils::createUUID())
{

}

CUIModule_ContentButtonGroup::~CUIModule_ContentButtonGroup()
{

}


void CUIModule_ContentButtonGroup::addDefinitionToJSON(CJSONWriter& writer, CJSONWriterObject& object)
{
	object.addString(AMC_API_KEY_UI_ITEMTYPE, "buttongroup");
	object.addString(AMC_API_KEY_UI_ITEMUUID, m_sUUID);

	CJSONWriterArray buttonArray(writer);

	for (auto pButton : m_Buttons) {
		CJSONWriterObject buttonobject(writer);
		buttonobject.addString(AMC_API_KEY_UI_BUTTONUUID, pButton->getUUID ());
		buttonobject.addString(AMC_API_KEY_UI_BUTTONCAPTION, pButton->getCaption ());
		buttonobject.addString(AMC_API_KEY_UI_BUTTONTARGETPAGE, pButton->getTargetPage ());
		buttonobject.addString(AMC_API_KEY_UI_BUTTONEVENT, pButton->getEvent());
		buttonArray.addObject(buttonobject);
	}


	object.addArray(AMC_API_KEY_UI_ITEMBUTTONS, buttonArray);

}



void CUIModule_ContentButtonGroup::addButton(const std::string& sCaption, const std::string& sTargetPage, const std::string& sEvent)
{
	m_Buttons.push_back(std::make_shared<CUIModule_ContentButton> (sCaption, sTargetPage, sEvent));
}
