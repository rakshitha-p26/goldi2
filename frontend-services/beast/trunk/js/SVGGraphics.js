/**
 * Created by maximilian on 12.05.17.
 */
var SVGGraphics;
(function (SVGGraphics_1) {
    const attrX = 'simcir-transform-x';
    const attrY = 'simcir-transform-y';
    const attrRotate = 'simcir-transform-rotate';
    const attrZoom = 'simcir-transform-zoom';
    /**
     *
     * @param tagName
     * @returns {JQuery}
     */
    function createSVGElement(tagName) {
        return $(document.createElementNS('http://www.w3.org/2000/svg', tagName));
    }
    SVGGraphics_1.createSVGElement = createSVGElement;
    ;
    /**
     *
     * @param width
     * @param height
     * @returns {JQuery}
     */
    function createSVG(width, height) {
        if (width === undefined || height === undefined)
            return createSVGElement('svg').attr({
                version: '1.1', width: "100%", height: "100%",
            });
        return createSVGElement('svg').attr({
            version: '1.1',
            width: width, height: height,
            viewBox: '0 0 ' + width + ' ' + height
        });
    }
    SVGGraphics_1.createSVG = createSVG;
    ;
    function transform($o, x, y, rotate, zoom) {
        const getNumber = function ($o, k) {
            var v = $o.attr(k);
            return v ? +v : 0;
        };
        if (arguments.length >= 3) {
            var transform = 'translate(' + x + ' ' + y + ')';
            if (rotate) {
                transform += ' rotate(' + rotate + ')';
            }
            if (zoom) {
                transform += ' scale(' + zoom + ')';
            }
            $o.attr('transform', transform);
            $o.attr(attrX, x);
            $o.attr(attrY, y);
            $o.attr(attrRotate, rotate);
            $o.attr(attrZoom, zoom);
            $o.trigger("tansformed");
        }
        else if (arguments.length == 1) {
            return { x: getNumber($o, attrX), y: getNumber($o, attrY),
                rotate: getNumber($o, attrZoom), zoom: getNumber($o, attrZoom) };
        }
    }
    SVGGraphics_1.transform = transform;
    ;
    /**
     * Class for manipuating jQuery SVG Objects
     */
    class SVGGraphics {
        constructor(target) {
            this.attr = {};
            this.buf = '';
            this.target = target;
        }
        moveTo(x, y) {
            this.buf += ' M ' + x + ' ' + y;
        }
        ;
        lineTo(x, y) {
            this.buf += ' L ' + x + ' ' + y;
        }
        ;
        curveTo(x1, y1, x, y) {
            this.buf += ' Q ' + x1 + ' ' + y1 + ' ' + x + ' ' + y;
        }
        ;
        closePath(close) {
            if (close) {
                // really close path.
                this.buf += ' Z';
            }
            this.target.append(createSVGElement('path').
                attr('d', this.buf).attr(this.attr));
            this.buf = '';
        }
        ;
        drawRect(x, y, width, height) {
            this.target.append(createSVGElement('rect').
                attr({ x: x, y: y, width: width, height: height }).attr(this.attr));
        }
        ;
        drawCircle(x, y, r) {
            this.target.append(createSVGElement('circle').
                attr({ cx: x, cy: y, r: r }).attr(this.attr));
        }
        ;
    }
    SVGGraphics_1.SVGGraphics = SVGGraphics;
    ;
})(SVGGraphics || (SVGGraphics = {}));
;
//# sourceMappingURL=SVGGraphics.js.map