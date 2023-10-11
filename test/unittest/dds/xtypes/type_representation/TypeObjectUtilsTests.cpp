// Copyright 2023 Proyectos y Sistemas de Mantenimiento SL (eProsima).
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

/**
 * @file
 * This file contains negative tests related to the TypeObjectUtils API.
 */

#include <gtest/gtest.h>

#include <fastdds/dds/xtypes/common.hpp>
#include <fastdds/dds/xtypes/exception/Exception.hpp>
#include <fastdds/dds/xtypes/type_representation/TypeObject.h>
#include <fastdds/dds/xtypes/type_representation/TypeObjectUtils.hpp>

namespace eprosima {
namespace fastdds {
namespace dds {
namespace xtypes1_3 {

// Build TypeObjectHashId object with wrong discriminator.
TEST(TypeObjectUtilsTests, build_type_object_hash_id_wrong_discriminator)
{
    uint8_t bad_discriminator = EK_BOTH;
    EquivalenceHash hash;
    EXPECT_THROW(TypeObjectHashId type_object_hash_id = TypeObjectUtils::build_type_object_hash_id(
        bad_discriminator, hash), InvalidArgumentError);
    EXPECT_NO_THROW(TypeObjectHashId type_object_hash_id = TypeObjectUtils::build_type_object_hash_id(
        EK_MINIMAL, hash));
    EXPECT_NO_THROW(TypeObjectHashId type_object_hash_id = TypeObjectUtils::build_type_object_hash_id(
        EK_COMPLETE, hash));
}

// Build StringSTypeDefn with bound equal 0 (INVALID_SBOUND).
TEST(TypeObjectUtilsTests, build_string_s_type_defn_invalid_bound)
{
    SBound wrong_bound = 0;
    EXPECT_THROW(StringSTypeDefn string_l_type_defn = TypeObjectUtils::build_string_s_type_defn(wrong_bound),
        InvalidArgumentError);
    EXPECT_NO_THROW(StringSTypeDefn string_l_type_defn = TypeObjectUtils::build_string_s_type_defn(1));
}


// Build StringLTypeDefn with bound smaller than 256.
TEST(TypeObjectUtilsTests, build_string_l_type_defn_small_bound)
{
    LBound wrong_bound = 255;
    EXPECT_THROW(StringLTypeDefn string_l_type_defn = TypeObjectUtils::build_string_l_type_defn(wrong_bound),
        InvalidArgumentError);
    EXPECT_NO_THROW(StringLTypeDefn string_l_type_defn = TypeObjectUtils::build_string_l_type_defn(256));
}

#if !defined(NDEBUG)
// Build PlainCollectionHeader with inconsistent CollectionElementFlag.
TEST(TypeObjectUtilsTests, build_plain_collection_header_inconsistent_element_flags)
{
    CollectionElementFlag wrong_element_flag = 0;
    CollectionElementFlag correct_element_flag = TypeObjectUtils::build_collection_element_flag(TryConstructKind::TRIM,
        false);
    EXPECT_THROW(PlainCollectionHeader plain_collection_header = TypeObjectUtils::build_plain_collection_header(
        EquivalenceKindValue::EK_BOTH, wrong_element_flag), InvalidArgumentError);
    EXPECT_NO_THROW(PlainCollectionHeader plain_collection_header = TypeObjectUtils::build_plain_collection_header(
        EquivalenceKindValue::EK_BOTH, correct_element_flag));
}
#endif // !defined(NDEBUG)

/* TODO(jlbueno): pending @external annotation implementation
// Build PlainSequenceSElemDefn with inconsistent parameters.
TEST(TypeObjectUtilsTests, build_plain_sequence_s_elem_defn_inconsistencies)
{
    TypeIdentifier test_identifier;
    CollectionElementFlag flags = TypeObjectUtils::build_collection_element_flag(TryConstructKind::TRIM, false);
#if !defined(NDEBUG)
    PlainCollectionHeader wrong_header;
    // Inconsistent header CollectionElementFlags
    EXPECT_THROW(PlainSequenceSElemDefn plain_seq = TypeObjectUtils::build_plain_sequence_s_elem_defn(
        wrong_header, 10, test_identifier), InvalidArgumentError);
    wrong_header.element_flags(flags);
    // Inconsistent header EquivalenceKind
    EXPECT_THROW(PlainSequenceSElemDefn plain_seq = TypeObjectUtils::build_plain_sequence_s_elem_defn(
        wrong_header, 10, test_identifier), InvalidArgumentError);
#endif // !defined(NDEBUG)
    PlainCollectionHeader complete_header = TypeObjectUtils::build_plain_collection_header(
        EquivalenceKindValue::EK_COMPLETE, flags);
    // Check SBound consistency
    SBound wrong_bound = 0;
    EXPECT_THROW(PlainSequenceSElemDefn plain_seq = TypeObjectUtils::build_plain_sequence_s_elem_defn(
        complete_header, wrong_bound, test_identifier), InvalidArgumentError);

    // Non-initialized TypeIdentifier
    EXPECT_THROW(PlainSequenceSElemDefn plain_seq = TypeObjectUtils::build_plain_sequence_s_elem_defn(
        complete_header, 10, test_identifier), InvalidArgumentError);
    // Primitive TypeIdentifier
    EXPECT_NO_THROW(test_identifier._d(TK_BOOLEAN));
    // TypeIdentifier inconsistent with complete header
    EXPECT_THROW(PlainSequenceSElemDefn plain_seq = TypeObjectUtils::build_plain_sequence_s_elem_defn(
        complete_header, 10, test_identifier), InvalidArgumentError);
    PlainCollectionHeader minimal_header = TypeObjectUtils::build_plain_collection_header(
        EquivalenceKindValue::EK_MINIMAL, flags);
    // TypeIdentifier inconsistent with minimal header
    EXPECT_THROW(PlainSequenceSElemDefn plain_seq = TypeObjectUtils::build_plain_sequence_s_elem_defn(
        minimal_header, 10, test_identifier), InvalidArgumentError);
    PlainCollectionHeader fully_descriptive_header = TypeObjectUtils::build_plain_collection_header(
        EquivalenceKindValue::EK_BOTH, flags);
    // TypeIdentifier consistent with fully-descriptive header
    EXPECT_NO_THROW(PlainSequenceSElemDefn plain_seq = TypeObjectUtils::build_plain_sequence_s_elem_defn(
        fully_descriptive_header, 10, test_identifier));
    
    // TODO(jlbueno) Add case of plain collection.

    // Change discriminator to EK_COMPLETE
    EquivalenceHash hash;
    test_identifier.equivalence_hash(hash);
    // TypeIdentifier consistent with complete header
    EXPECT_NO_THROW(PlainSequenceSElemDefn plain_seq = TypeObjectUtils::build_plain_sequence_s_elem_defn(
        complete_header, 10, test_identifier));
    // TypeIdentifier inconsistent with minimal header
    EXPECT_THROW(PlainSequenceSElemDefn plain_seq = TypeObjectUtils::build_plain_sequence_s_elem_defn(
        minimal_header, 10, test_identifier), InvalidArgumentError);
    // TypeIdentifier inconsistent with fully-descriptive header
    EXPECT_THROW(PlainSequenceSElemDefn plain_seq = TypeObjectUtils::build_plain_sequence_s_elem_defn(
        fully_descriptive_header, 10, test_identifier), InvalidArgumentError);
    // Change discriminator to EK_MINIMAL
    EXPECT_NO_THROW(test_identifier._d(EK_MINIMAL));
    // TypeIdentifier inconsistent with complete header
    EXPECT_THROW(PlainSequenceSElemDefn plain_seq = TypeObjectUtils::build_plain_sequence_s_elem_defn(
        complete_header, 10, test_identifier), InvalidArgumentError);
    // TypeIdentifier consistent with minimal header
    EXPECT_NO_THROW(PlainSequenceSElemDefn plain_seq = TypeObjectUtils::build_plain_sequence_s_elem_defn(
        minimal_header, 10, test_identifier));
    // TypeIdentifier inconsistent with fully-descriptive header
    EXPECT_THROW(PlainSequenceSElemDefn plain_seq = TypeObjectUtils::build_plain_sequence_s_elem_defn(
        fully_descriptive_header, 10, test_identifier), InvalidArgumentError);
}

// Build PlainSequenceLElemDefn with inconsistent parameters.
TEST(TypeObjectUtilsTests, build_plain_sequence_l_elem_defn_inconsistencies)
{
    TypeIdentifier test_identifier;
    CollectionElementFlag flags = TypeObjectUtils::build_collection_element_flag(TryConstructKind::TRIM, false);
#if !defined(NDEBUG)
    PlainCollectionHeader wrong_header;
    // Inconsistent header CollectionElementFlags
    EXPECT_THROW(PlainSequenceLElemDefn plain_seq = TypeObjectUtils::build_plain_sequence_l_elem_defn(
        wrong_header, 256, test_identifier), InvalidArgumentError);
    wrong_header.element_flags(flags);
    // Inconsistent header EquivalenceKind
    EXPECT_THROW(PlainSequenceLElemDefn plain_seq = TypeObjectUtils::build_plain_sequence_l_elem_defn(
        wrong_header, 256, test_identifier), InvalidArgumentError);
#endif // !defined(NDEBUG)
    PlainCollectionHeader complete_header = TypeObjectUtils::build_plain_collection_header(
        EquivalenceKindValue::EK_COMPLETE, flags);
    // Check LBound consistency
    LBound wrong_bound = 255;
    EXPECT_THROW(PlainSequenceLElemDefn plain_seq = TypeObjectUtils::build_plain_sequence_l_elem_defn(
        complete_header, wrong_bound, test_identifier), InvalidArgumentError);

    // Non-initialized TypeIdentifier
    EXPECT_THROW(PlainSequenceLElemDefn plain_seq = TypeObjectUtils::build_plain_sequence_l_elem_defn(
        complete_header, 256, test_identifier), InvalidArgumentError);
    // Primitive TypeIdentifier
    EXPECT_NO_THROW(test_identifier._d(TK_BOOLEAN));
    // TypeIdentifier inconsistent with complete header
    EXPECT_THROW(PlainSequenceLElemDefn plain_seq = TypeObjectUtils::build_plain_sequence_l_elem_defn(
        complete_header, 256, test_identifier), InvalidArgumentError);
    PlainCollectionHeader minimal_header = TypeObjectUtils::build_plain_collection_header(
        EquivalenceKindValue::EK_MINIMAL, flags);
    // TypeIdentifier inconsistent with minimal header
    EXPECT_THROW(PlainSequenceLElemDefn plain_seq = TypeObjectUtils::build_plain_sequence_l_elem_defn(
        minimal_header, 256, test_identifier), InvalidArgumentError);
    PlainCollectionHeader fully_descriptive_header = TypeObjectUtils::build_plain_collection_header(
        EquivalenceKindValue::EK_BOTH, flags);
    // TypeIdentifier consistent with fully-descriptive header
    EXPECT_NO_THROW(PlainSequenceLElemDefn plain_seq = TypeObjectUtils::build_plain_sequence_l_elem_defn(
        fully_descriptive_header, 256, test_identifier));
    
    // TODO(jlbueno) Add case of plain collection.

    // Change discriminator to EK_COMPLETE
    EquivalenceHash hash;
    test_identifier.equivalence_hash(hash);
    // TypeIdentifier consistent with complete header
    EXPECT_NO_THROW(PlainSequenceLElemDefn plain_seq = TypeObjectUtils::build_plain_sequence_l_elem_defn(
        complete_header, 256, test_identifier));
    // TypeIdentifier inconsistent with minimal header
    EXPECT_THROW(PlainSequenceLElemDefn plain_seq = TypeObjectUtils::build_plain_sequence_l_elem_defn(
        minimal_header, 256, test_identifier), InvalidArgumentError);
    // TypeIdentifier inconsistent with fully-descriptive header
    EXPECT_THROW(PlainSequenceLElemDefn plain_seq = TypeObjectUtils::build_plain_sequence_l_elem_defn(
        fully_descriptive_header, 256, test_identifier), InvalidArgumentError);
    // Change discriminator to EK_MINIMAL
    EXPECT_NO_THROW(test_identifier._d(EK_MINIMAL));
    // TypeIdentifier inconsistent with complete header
    EXPECT_THROW(PlainSequenceLElemDefn plain_seq = TypeObjectUtils::build_plain_sequence_l_elem_defn(
        complete_header, 256, test_identifier), InvalidArgumentError);
    // TypeIdentifier consistent with minimal header
    EXPECT_NO_THROW(PlainSequenceLElemDefn plain_seq = TypeObjectUtils::build_plain_sequence_l_elem_defn(
        minimal_header, 256, test_identifier));
    // TypeIdentifier inconsistent with fully-descriptive header
    EXPECT_THROW(PlainSequenceLElemDefn plain_seq = TypeObjectUtils::build_plain_sequence_l_elem_defn(
        fully_descriptive_header, 256, test_identifier), InvalidArgumentError);
}

// Build PlainArraySElemDefn with inconsistent parameters.
TEST(TypeObjectUtilsTests, build_plain_array_s_elem_defn_inconsistencies)
{
    TypeIdentifier test_identifier;
    CollectionElementFlag flags = TypeObjectUtils::build_collection_element_flag(TryConstructKind::TRIM, false);
    SBoundSeq bound_seq;
    TypeObjectUtils::add_array_dimension(bound_seq, 10);
#if !defined(NDEBUG)
    PlainCollectionHeader wrong_header;
    // Inconsistent header CollectionElementFlags
    EXPECT_THROW(PlainArraySElemDefn plain_array = TypeObjectUtils::build_plain_array_s_elem_defn(
        wrong_header, bound_seq, test_identifier), InvalidArgumentError);
    wrong_header.element_flags(flags);
    // Inconsistent header EquivalenceKind
    EXPECT_THROW(PlainArraySElemDefn plain_array = TypeObjectUtils::build_plain_array_s_elem_defn(
        wrong_header, bound_seq, test_identifier), InvalidArgumentError);
#endif // !defined(NDEBUG)
    PlainCollectionHeader complete_header = TypeObjectUtils::build_plain_collection_header(
        EquivalenceKindValue::EK_COMPLETE, flags);
    // Check SBoundSeq consistency
    SBoundSeq wrong_bound_seq;
    // Empty array_bound_seq
    EXPECT_THROW(PlainArraySElemDefn plain_array = TypeObjectUtils::build_plain_array_s_elem_defn(
        complete_header, wrong_bound_seq, test_identifier), InvalidArgumentError);
    // Zero element
    TypeObjectUtils::add_array_dimension(wrong_bound_seq, 10);
    TypeObjectUtils::add_array_dimension(wrong_bound_seq, 0);
    EXPECT_THROW(PlainArraySElemDefn plain_array = TypeObjectUtils::build_plain_array_s_elem_defn(
        complete_header, wrong_bound_seq, test_identifier), InvalidArgumentError);

    // Non-initialized TypeIdentifier
    EXPECT_THROW(PlainArraySElemDefn plain_array = TypeObjectUtils::build_plain_array_s_elem_defn(
        complete_header, bound_seq, test_identifier), InvalidArgumentError);
    // Primitive TypeIdentifier
    EXPECT_NO_THROW(test_identifier._d(TK_BOOLEAN));
    // TypeIdentifier inconsistent with complete header
    EXPECT_THROW(PlainArraySElemDefn plain_array = TypeObjectUtils::build_plain_array_s_elem_defn(
        complete_header, bound_seq, test_identifier), InvalidArgumentError);
    PlainCollectionHeader minimal_header = TypeObjectUtils::build_plain_collection_header(
        EquivalenceKindValue::EK_MINIMAL, flags);
    // TypeIdentifier inconsistent with minimal header
    EXPECT_THROW(PlainArraySElemDefn plain_array = TypeObjectUtils::build_plain_array_s_elem_defn(
        minimal_header, bound_seq, test_identifier), InvalidArgumentError);
    PlainCollectionHeader fully_descriptive_header = TypeObjectUtils::build_plain_collection_header(
        EquivalenceKindValue::EK_BOTH, flags);
    // TypeIdentifier consistent with fully-descriptive header
    EXPECT_NO_THROW(PlainArraySElemDefn plain_array = TypeObjectUtils::build_plain_array_s_elem_defn(
        fully_descriptive_header, bound_seq, test_identifier));
    
    // TODO(jlbueno) Add case of plain collection.

    // Change discriminator to EK_COMPLETE
    EquivalenceHash hash;
    test_identifier.equivalence_hash(hash);
    // TypeIdentifier consistent with complete header
    EXPECT_NO_THROW(PlainArraySElemDefn plain_array = TypeObjectUtils::build_plain_array_s_elem_defn(
        complete_header, bound_seq, test_identifier));
    // TypeIdentifier inconsistent with minimal header
    EXPECT_THROW(PlainArraySElemDefn plain_array = TypeObjectUtils::build_plain_array_s_elem_defn(
        minimal_header, bound_seq, test_identifier), InvalidArgumentError);
    // TypeIdentifier inconsistent with fully-descriptive header
    EXPECT_THROW(PlainArraySElemDefn plain_array = TypeObjectUtils::build_plain_array_s_elem_defn(
        fully_descriptive_header, bound_seq, test_identifier), InvalidArgumentError);
    // Change discriminator to EK_MINIMAL
    EXPECT_NO_THROW(test_identifier._d(EK_MINIMAL));
    // TypeIdentifier inconsistent with complete header
    EXPECT_THROW(PlainArraySElemDefn plain_array = TypeObjectUtils::build_plain_array_s_elem_defn(
        complete_header, bound_seq, test_identifier), InvalidArgumentError);
    // TypeIdentifier consistent with minimal header
    EXPECT_NO_THROW(PlainArraySElemDefn plain_array = TypeObjectUtils::build_plain_array_s_elem_defn(
        minimal_header, bound_seq, test_identifier));
    // TypeIdentifier inconsistent with fully-descriptive header
    EXPECT_THROW(PlainArraySElemDefn plain_array = TypeObjectUtils::build_plain_array_s_elem_defn(
        fully_descriptive_header, bound_seq, test_identifier), InvalidArgumentError);
}

// Build PlainArrayLElemDefn with inconsistent parameters.
TEST(TypeObjectUtilsTests, build_plain_array_l_elem_defn_inconsistencies)
{
    TypeIdentifier test_identifier;
    CollectionElementFlag flags = TypeObjectUtils::build_collection_element_flag(TryConstructKind::TRIM, false);
    LBoundSeq bound_seq;
    TypeObjectUtils::add_array_dimension(bound_seq, 256);
#if !defined(NDEBUG)
    PlainCollectionHeader wrong_header;
    // Inconsistent header CollectionElementFlags
    EXPECT_THROW(PlainArrayLElemDefn plain_array = TypeObjectUtils::build_plain_array_l_elem_defn(
        wrong_header, bound_seq, test_identifier), InvalidArgumentError);
    wrong_header.element_flags(flags);
    // Inconsistent header EquivalenceKind
    EXPECT_THROW(PlainArrayLElemDefn plain_array = TypeObjectUtils::build_plain_array_l_elem_defn(
        wrong_header, bound_seq, test_identifier), InvalidArgumentError);
#endif // !defined(NDEBUG)
    PlainCollectionHeader complete_header = TypeObjectUtils::build_plain_collection_header(
        EquivalenceKindValue::EK_COMPLETE, flags);
    // Check SBoundSeq consistency
    LBoundSeq wrong_bound_seq;
    // Empty array_bound_seq
    EXPECT_THROW(PlainArrayLElemDefn plain_array = TypeObjectUtils::build_plain_array_l_elem_defn(
        complete_header, wrong_bound_seq, test_identifier), InvalidArgumentError);
    // Non-large bound dimension
    TypeObjectUtils::add_array_dimension(wrong_bound_seq, 10);
    EXPECT_THROW(PlainArrayLElemDefn plain_array = TypeObjectUtils::build_plain_array_l_elem_defn(
        complete_header, wrong_bound_seq, test_identifier), InvalidArgumentError);

    // Non-initialized TypeIdentifier
    EXPECT_THROW(PlainArrayLElemDefn plain_array = TypeObjectUtils::build_plain_array_l_elem_defn(
        complete_header, bound_seq, test_identifier), InvalidArgumentError);
    // Primitive TypeIdentifier
    EXPECT_NO_THROW(test_identifier._d(TK_BOOLEAN));
    // TypeIdentifier inconsistent with complete header
    EXPECT_THROW(PlainArrayLElemDefn plain_array = TypeObjectUtils::build_plain_array_l_elem_defn(
        complete_header, bound_seq, test_identifier), InvalidArgumentError);
    PlainCollectionHeader minimal_header = TypeObjectUtils::build_plain_collection_header(
        EquivalenceKindValue::EK_MINIMAL, flags);
    // TypeIdentifier inconsistent with minimal header
    EXPECT_THROW(PlainArrayLElemDefn plain_array = TypeObjectUtils::build_plain_array_l_elem_defn(
        minimal_header, bound_seq, test_identifier), InvalidArgumentError);
    PlainCollectionHeader fully_descriptive_header = TypeObjectUtils::build_plain_collection_header(
        EquivalenceKindValue::EK_BOTH, flags);
    // TypeIdentifier consistent with fully-descriptive header
    EXPECT_NO_THROW(PlainArrayLElemDefn plain_array = TypeObjectUtils::build_plain_array_l_elem_defn(
        fully_descriptive_header, bound_seq, test_identifier));
    // At least one dimension should be large
    TypeObjectUtils::add_array_dimension(wrong_bound_seq, 256);
    EXPECT_NO_THROW(PlainArrayLElemDefn plain_array = TypeObjectUtils::build_plain_array_l_elem_defn(
        complete_header, wrong_bound_seq, test_identifier));
    // Zero element
    TypeObjectUtils::add_array_dimension(wrong_bound_seq, 0);
    EXPECT_THROW(PlainArrayLElemDefn plain_array = TypeObjectUtils::build_plain_array_l_elem_defn(
        complete_header, wrong_bound_seq, test_identifier), InvalidArgumentError);

    // TODO(jlbueno) Add case of plain collection.

    // Change discriminator to EK_COMPLETE
    EquivalenceHash hash;
    test_identifier.equivalence_hash(hash);
    // TypeIdentifier consistent with complete header
    EXPECT_NO_THROW(PlainArrayLElemDefn plain_array = TypeObjectUtils::build_plain_array_l_elem_defn(
        complete_header, bound_seq, test_identifier));
    // TypeIdentifier inconsistent with minimal header
    EXPECT_THROW(PlainArrayLElemDefn plain_array = TypeObjectUtils::build_plain_array_l_elem_defn(
        minimal_header, bound_seq, test_identifier), InvalidArgumentError);
    // TypeIdentifier inconsistent with fully-descriptive header
    EXPECT_THROW(PlainArrayLElemDefn plain_array = TypeObjectUtils::build_plain_array_l_elem_defn(
        fully_descriptive_header, bound_seq, test_identifier), InvalidArgumentError);
    // Change discriminator to EK_MINIMAL
    EXPECT_NO_THROW(test_identifier._d(EK_MINIMAL));
    // TypeIdentifier inconsistent with complete header
    EXPECT_THROW(PlainArrayLElemDefn plain_array = TypeObjectUtils::build_plain_array_l_elem_defn(
        complete_header, bound_seq, test_identifier), InvalidArgumentError);
    // TypeIdentifier consistent with minimal header
    EXPECT_NO_THROW(PlainArrayLElemDefn plain_array = TypeObjectUtils::build_plain_array_l_elem_defn(
        minimal_header, bound_seq, test_identifier));
    // TypeIdentifier inconsistent with fully-descriptive header
    EXPECT_THROW(PlainArrayLElemDefn plain_array = TypeObjectUtils::build_plain_array_l_elem_defn(
        fully_descriptive_header, bound_seq, test_identifier), InvalidArgumentError);
}
*/

} // xtypes1_3
} // dds
} // fastdds
} // eprosima

int main(
        int argc,
        char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
