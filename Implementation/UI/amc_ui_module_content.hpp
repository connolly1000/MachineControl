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


#ifndef __AMC_UI_MODULE_CONTENT
#define __AMC_UI_MODULE_CONTENT

#include "header_protection.hpp"

#ifndef __AMCIMPL_UI_MODULE
#error this header is protected and should only be included in the corresponding implementation CPP files.
#endif

#include "Libraries/PugiXML/pugixml.hpp"
#include "amc_ui_module_contentitem_form.hpp"
#include "amc_ui_interfaces.hpp"

namespace LibMCData {
	amcDeclareDependingClass(CBuildJobHandler, PBuildJobHandler);
}


namespace AMC {

	amcDeclareDependingClass(CUIModule, PUIModule);
	amcDeclareDependingClass(CUIModule_Content, PUIModule_Content);
	amcDeclareDependingClass(CUIModule_ContentItem, PUIModule_ContentItem);
	amcDeclareDependingClass(CUIModule_ContentForm, PUIModule_ContentForm);
	amcDeclareDependingClass(CStateMachineData, PStateMachineData);
	amcDeclareDependingClass(CResourcePackage, PResourcePackage);
	amcDeclareDependingClass(CUIModule_ContentFormRegistry, PUIModule_ContentFormRegistry);
	

	class CUIModule_Content : public CUIModule {
	protected:		

		std::string m_sHeadLine;
		std::string m_sCaption;
		std::string m_sTitle;
		std::string m_sSubtitle;

		std::map<std::string, PUIModule_ContentItem> m_ItemMap;
		std::vector<PUIModule_ContentItem> m_Items;

		void addItem(PUIModule_ContentItem pItem);

	public:

		CUIModule_Content(pugi::xml_node & xmlNode, PUIModuleEnvironment pUIModuleEnvironment);
		
		virtual ~CUIModule_Content();

		virtual std::string getType() override;

		virtual std::string getCaption() override;

		static std::string getStaticType();

		std::string getHeadLine ();
		std::string getTitle ();
		std::string getSubtitle ();

		virtual void writeDefinitionToJSON(CJSONWriter& writer, CJSONWriterObject& moduleObject) override;

		virtual void populateItemMap(std::map<std::string, PUIModuleItem>& itemMap) override;


		virtual PUIModuleItem findItem(const std::string& sUUID) override;

		void configurePostLoading() override;

	};

	
}


#endif //__AMC_UI_MODULE_CONTENT

