package org.glmdb.blueprints.jni;

/**
 * Date: 2013/11/23
 * Time: 5:55 PM
 */
class PropertyKeyEnumAndId {

    PropertyTypeEnum propertyTypeEnum;
    int id;
    boolean indexed;

    PropertyKeyEnumAndId(PropertyTypeEnum propertyTypeEnum, int id, boolean indexed) {
        this.propertyTypeEnum = propertyTypeEnum;
        this.id = id;
        this.indexed = indexed;
    }

}
