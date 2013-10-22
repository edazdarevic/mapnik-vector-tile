// mapnik
#include <mapnik/map.hpp>
#include <mapnik/layer.hpp>
#include <mapnik/rule.hpp>
#include <mapnik/feature_type_style.hpp>
#include <mapnik/rule.hpp>
#include <mapnik/markers_symbolizer.hpp>
#include <mapnik/image_util.hpp>
#include <mapnik/graphics.hpp>
#include <mapnik/agg_renderer.hpp>
#include <mapnik/save_map.hpp>
#include <mapnik/map.hpp>
#include <mapnik/feature.hpp>
#include <mapnik/feature_factory.hpp>
#include <mapnik/unicode.hpp>
#include <mapnik/geometry.hpp>
#include <mapnik/datasource.hpp>
#include <mapnik/memory_datasource.hpp>

#include <memory>
#include <string>

std::shared_ptr<mapnik::memory_datasource> build_ds() {
    mapnik::context_ptr ctx = std::make_shared<mapnik::context_type>();
    ctx->push("name");
    mapnik::feature_ptr feature(mapnik::feature_factory::create(ctx,1));
    mapnik::transcoder tr("utf-8");
    UnicodeString ustr = tr.transcode("null island");
    feature->put("name",ustr);
    mapnik::geometry_type * pt = new mapnik::geometry_type(mapnik::geometry_type::types::Point);
    pt->move_to(0,0);
    feature->add_geometry(pt);
    std::shared_ptr<mapnik::memory_datasource> ds = std::make_shared<mapnik::memory_datasource>();
    ds->push(feature);
    return ds;
}
