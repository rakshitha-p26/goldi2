/*
@license
Copyright (c) 2016 The Polymer Project Authors. All rights reserved.
This code may only be used under the BSD style license found at http://polymer.github.io/LICENSE.txt
The complete set of authors may be found at http://polymer.github.io/AUTHORS.txt
The complete set of contributors may be found at http://polymer.github.io/CONTRIBUTORS.txt
Code distributed by Google as part of the polymer project is also
subject to an additional IP rights grant found at http://polymer.github.io/PATENTS.txt
*/

import "./sane-venn-diagram";

import { html } from "@polymer/polymer/polymer-element.js";
import { AppLocalizeMixin } from "./custom-type-base-lib.js";

class SaneView2 extends AppLocalizeMixin() {
	static get template() {
		return html`
			<style include="shared-styles">
				:host {
					display: block;
					padding: 10px;
				}
        	</style>

	  		<div class="card">
		  		<div class="card-header">
			  		<div class="circle"><iron-icon icon="image:adjust"></iron-icon></div>
			  		<h1 class="view-name">[[localize('title-BMA')]]</h1>
		  		</div>
				<div class="card-body">
					<sane-venn-diagram data=[[data]]></sane-venn-diagram>
				</div>
			</div>
		`;
	}

	static get is() {
		return "sane-view2";
	}

	public ready() {
		super.ready();
		this.loadResources(this.resolveUrl("src/locales.json"), null, null);
	}
}

customElements.define(SaneView2.is, SaneView2);
